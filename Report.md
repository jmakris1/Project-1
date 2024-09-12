# Project 1 Report
# Jerry Makris
# CS 2240
# Section B
# Project 1

Answer the following prompts directly in this file:
* What each of the 5+ attributes of your dataset represent.
  Attributes:
    RowID - A unique integer numbering each row starting at the first data point (not the header)
    Year - The year the flight took place
    Quarter - An integer representing the quarter of the year the flight took place (1-4)
    Origin City - A string representing the city the flight took off from.
    Destination City - A string representing the city the flight landed at.
    Origin Airport - A string representing the 3 letter airport code of the origin airport.
    Destination Airport - A string representing the 3 letter airport code of the destination airport.
    Distance - An integer representing the distance in miles of the flight path.
    Passengers - An integer representing the number of passengers on the flight.
    Fare - A double representing the average fare for the purchased tickets on the flight.

* Where you got the data from.
    Data was retrieved from a larger dataset of flight information on Kaggle, at this link:
    https://www.kaggle.com/datasets/bhavikjikadara/us-airline-flight-routes-and-fares-1993-2024.
    The original dataset contained data since 1993, but I decided to only use 2023-2024 due to 
    the number of entries.

* Why you chose that dataset.
    I chose this dataset because it seemed interesting to me to see how many flights occur each year
    and from which cities. Hopefully in future projects I can do some more meaningful calculations on 
    the data to assess which cities were most popular and how the time of year affects flight demand 
    and flight fare. I also noticed the dataset was very complete and contained little to no empty values,
    with consistently formatted fields and entries.

* How the rows are ordered by default (i.e. is the data sorted by a particular column?).
    The data was sorted by time ascending, showing data for the 1st quarter of the earliest year first, and
    the most recent quarter of the most recent year last. It was then sorted alphabetically by Origin City.
* How you know your functions work correctly.
    I know my functions work correctly because all of my function call tests do not throw any errors or messages
    to the prompt. The number of records C++ reads in is equivalent to the number of records in the csv file. 
    If any other functions were not working properly, the output of the vector would not compute properly, and 
    my calculations for average distance and average passengers would be incorrect. 

* Why you chose that calculation for your dataset.
    I chose to calculate average distance and average passengers per flight because I thought it would be insightful
    to see if there is any large differences between the two years. I also knew it would test the operation of some of
    my getters.

**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**