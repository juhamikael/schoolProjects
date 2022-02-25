import random

# Initialize few lists, we are going to use these later on
firstname_list = []
fixed_firstname_list = [] 
lastname_list = []
fixed_lastname_list = []
values_list = []
phone_area_codes = ["453","345","854","941","225"]
departments = [3,4,5,6,7]

# On initialized database, last employee id is 15 this is +1 of last employee index
# If you use this multiple times, check last employee index from Adminer and start from +1
id_index = 16

# Read req_etunimia.txt and append them into firstname_list
with open('req_firstnames.txt') as f:
    lines = f.readlines()
    for i in lines:
        firstname_list.append(i)
# On read lines, there is linebreak "\n" in every name, we need to modify string a little bit and remove last 2 chars
# and add it to new list
for i in firstname_list:
    fixed_firstname_list.append(i[:-1])
# Repeat of last step but for lastnames
with open('req_lastnames.txt') as f:
    lines = f.readlines()
    for i in lines:
        lastname_list.append(i)
for i in lastname_list:
    fixed_lastname_list.append(i[:-1])



# x = Amount of employees we want to generate
amount_of_employees = 250
for i in range(amount_of_employees):
    # Random birthdays
    r_birth_year = random.randint(1986,1998)
    r_birth_month = random.randint(1,12)
    r_birth_day = random.randint(1,27)

    # Every number output < 10 is 1,2,3,4....
    # We want to turn the whole number to str and add 0 before value < 10
    if r_birth_month < 10:
        r_birth_month = f"0{r_birth_month}"
    if r_birth_day < 10:
        r_birth_day = f"0{r_birth_day}"

    # Choose random first and last name from fixed lists
    random_firstname = random.choice(fixed_firstname_list)
    random_lastname = random.choice(fixed_lastname_list)

    # Randomize salary from between 2200 and x, every 25 steps
    random_salary = random.randrange(2200, 5200, 25)
    department_id = random.choice(departments)

    # If Logic chain to decide supervisor_id, these are defined in /init_db/db.sql
    #####################
    # if department_id on 3, employee is salesman and salary is from between 2000 and 2800, incrementing by 50 steps 
    if department_id == 3:
        supervisor_id = 3
        random_salary = random.randrange(2000, 2800, 50)
    elif department_id == 4 and random_salary < 4000:
        supervisor_id = 8
    elif (department_id == 4 or department_id == 5 and random_salary > 3700 ) or (department_id == 4 or department_id == 5 and random_salary <= 3700):
        supervisor_id = 10
    elif (department_id == 5 and random_salary < 3500):
        supervisor_id = 14
    elif department_id == 6:
        supervisor_id = 1
        random_salary = random.randrange(5000, 6000, 100)
    elif department_id == 7:
        supervisor_id = 10
        random_salary = random.randrange(2200, 3500, 100)
    else:
        supervisor_id = 1

    ## If salary is over 6000, randomized person is on top of company hierarchy
    if random_salary > 6000:
        supervisor_id = 1
        department_id = 1
        random_salary = random.randrange(6000, 6700, 100)

    # As we can see, all of these strings are really long, we just split these here
    values_1st_string = f"({id_index+i}, '{random_firstname}', '{random_lastname}', {random_salary}, '{r_birth_year}-{r_birth_month}-{r_birth_day}',"
    values_2nd_string = f"'{random_firstname.lower()}.{random_lastname.lower()}@firma.fi', {department_id}, '{random.choice(phone_area_codes)}{random.randint(1111111,9999999)}', "
    values_3rd_string = f"'{random.choice(phone_area_codes)}{random.randint(1111111,9999999)}', NULL, {supervisor_id}),"
    
    # And combine them to one long string here
    values = f"{values_1st_string}{values_2nd_string}{values_3rd_string}"

    #Append VALUEs to empty list we made at the beginning
    values_list.append(values)
    
# On values_list last value there is comma, we need to change it to semicolon, otherwise the SQL command would not work
last_index = str(values_list[len(values_list)-1])[:-1]
last_index = (f"{last_index};")

# Deleting last value from the list and appending new value
values_list.pop()
values_list.append(last_index)


# String : SQL table where to INSERT  
new_dep = "INSERT INTO `department` (`id`, `name`, `manager_id`) VALUES (6, 'Ohjelmistokehitys',NULL), (7, 'IT-Tuki',NULL);"
insert = f"INSERT INTO `employee` (`id`, `fname`, `lname`, `salary`, `bdate`, `email`, `department_id`, `phone1`, `phone2`, `image`, `supervisor_id`)"

# Store the data to SQL file, which we can execute on Adminer or with other SQL tools
with open('SQL_insert_into_employee_RESULT.sql', 'w') as f:
    f.write(f"{new_dep}\n")
    f.write(f"{insert}\n")
    f.write("VALUES\n") 
    #Iterating values_list and writing all values
    for i in values_list: f.write(f"{i}\n")

# Print INSERT INTO and the first and last values from the list
print(f"{new_dep}")
print(f"{insert}")
print(("VALUES"))
print(values_list[0])
print(values_list[len(values_list)-1])