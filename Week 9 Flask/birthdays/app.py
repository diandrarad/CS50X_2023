import os
import secrets
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request

# Configure application
app = Flask(__name__)
app.secret_key = 'secrets.token_hex(16)'

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        # Add the user's entry into the database
        db.execute("INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?)", name, month, day)
        flash("Birthday added successfully!")

    # Display the entries in the database on index.html
    birthdays = db.execute("SELECT * FROM birthdays")
    return render_template("index.html", birthdays=birthdays)

@app.route("/delete/<int:id>", methods=["GET", "POST"])
def delete(id):
    if request.method == "POST":
        # Delete the entry with the specified ID
        db.execute("DELETE FROM birthdays WHERE id = ?", id)
        flash("Birthday deleted successfully!")
        return redirect("/")

    birthday = db.execute("SELECT * FROM birthdays WHERE id = ?", id)
    return render_template("delete.html", birthday=birthday[0])

@app.route("/edit/<int:id>", methods=["GET", "POST"])
def edit(id):
    if request.method == "POST":
        # Update the entry with the specified ID
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")
        db.execute("UPDATE birthdays SET name = ?, month = ?, day = ? WHERE id = ?", name, month, day, id)
        flash("Birthday updated successfully!")
        return redirect("/")

    birthday = db.execute("SELECT * FROM birthdays WHERE id = ?", id)
    return render_template("edit.html", birthday=birthday[0])


