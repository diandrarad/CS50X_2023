import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ").strip().capitalize()
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    new_cases = {}
    previous_cases = {}

    for row in reader:
        state = row['state']
        cases = int(row['cases'])

        # Calculate new cases for this day
        if state not in previous_cases:
            new_cases[state] = []
            previous_cases[state] = 0

        new_cases[state].append(cases - previous_cases[state])
        if len(new_cases[state]) > 14:
            new_cases[state].pop(0)

        # Update previous_cases
        previous_cases[state] = cases

    return new_cases


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        cases = new_cases[state]
        this_week = sum(cases[-7:]) / 7
        last_week = sum(cases[-14:-7]) / 7
        try:
            percent_change = (this_week - last_week) / last_week * 100
        except ZeroDivisionError:
            percent_change = 0
        print(f"{state} had a 7-day average of {this_week:.0f} and ", end="")
        if percent_change > 0:
            print(f"an increase of {percent_change:+.0f}%")
        else:
            print(f"a decrease of {percent_change:+.0f}%")


main()
