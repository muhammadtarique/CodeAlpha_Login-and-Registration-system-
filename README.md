# Login & Registration System (C++)

A simple console-based login and registration system in C++ that stores user credentials in a text file.  
Created as an internship task at **CodeAlpha**.

## Features
- Register a new user (with validation).
- Prevent duplicate usernames.
- Login using saved credentials from `usersRecords.txt`.

## File Used
- `usersRecords.txt` stores: `username password` (one record per line).

## Compile & Run
```bash
g++ main.cpp -o app
./app
