import csv
import sqlite3

# Open the CSV file and read the data
with open('students.csv') as csv_file:
    csv_reader = csv.DictReader(csv_file)
    student_data = [(int(row['id']), row['student_name'], row['house'], row['head']) for row in csv_reader]

# Connect to the database
conn = sqlite3.connect('database.db')
c = conn.cursor()

# Insert the unique houses into the houses table
houses = list(set([row[2:] for row in student_data]))
house_data = [(i, house[0], house[1]) for i, house in enumerate(houses, 1)]
c.executemany('INSERT INTO houses VALUES (?, ?, ?)', house_data)

# Map the house names to their respective IDs
house_map = {house[1]: house[0] for house in house_data}

# Insert the house assignments into the house_assignment table
house_assignment_data = [(row[0], house_map[row[2]]) for row in student_data]
c.executemany('INSERT INTO house_assignment VALUES (?, ?)', house_assignment_data)

# Commit the changes and close the connection
conn.commit()
conn.close()
