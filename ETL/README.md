# Extracting Data from CSV files

This assignment is based on a problem solved in enterprise computing: Extraction, Transformation, and Loading, also known as ETL. The inputs are data extracted from a leading aviation industry data
and consulting firm, GCR (See GCR.com for additional information).
The data is in CSV (Comma-Separated Values) format, where each data element is separated from the previous and following data elements by using a comma.

# Objective

The objective of this assignment was to demonstrate proficiency in file I/O, data structures and transformations using the C language.

# Extraction

The first part of ETL is Extration. This program accepts text files passed in (from the command line or otherwise). The data contained in the file is then read into memory and stored until the end of
the program, when all memory is freed.

# Specifications

These are the fields contained in the CSV files passed in to the program:

FAA Site Number (Contains leading digits followed by a decimal point and short text)

Loc ID (Location ID, or the airport's short name, i.e. MCO for Orlando)

Airport Name (The Airport's full name, i.e. Orlando International)

Associated City

State

Region (FAA Region)

ADO (Airline Dispatch Office)

Use (Public or Private)

Latitude

Longitude

Airport Ownnership (Public or Private)

Part 139 (FAA Regulation)

NPIAS Service Level (National Plan Integrated Airport Systems Descriptor)

NPIAS Hub Type (Intentionally left blank)

Airport Control Tower (Y/N)

Fuel (Fuel types available)

Other Services (Collections of tag indicating Instructions, etc)

Based Aircraft Total (Number of aircrafts - may be blank)

Total Operations (Takeoffs/Landings/etc - may be blank)

# Transformation

The program reads the text file into a buffer and parses it based on the commas between the data fields specified above. The parsed data is then used to populate a struct (i.e. the data has been
transformed from CSV to a data structure). In the specified structure, not all of the field names are used.

# Loading

After transforming the data, it can now be easily accessed by functions or other programs (i.e. loaded). This program passes the data to a print function and prints it to STDOUT.
