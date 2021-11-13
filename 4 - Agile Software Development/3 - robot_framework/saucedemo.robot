*** Settings ***
Documentation   Robot Framework - Test automation
Resource        ./saucedemo.resource

*** Test Cases ***
Access web
    Open correct website

Login-info
    Type Username
    Type Password
    Login

Add item
    Add item to cart

Checkout
    Open Cart
    Checkout
    Name and Postal

Finish
    Finish shopping
    Close


