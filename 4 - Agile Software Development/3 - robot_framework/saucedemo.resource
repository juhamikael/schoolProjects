*** Settings ***
Library         Selenium2Library

*** Variables ***
${SERVER}           https://www.saucedemo.com/
${BROWSER}          chrome
${USER}             performance_glitch_user
${PASSWORD}         secret_sauce
${NAME}             name=
${ID}               id=

***Keywords***
Open correct website
    Open Browser    ${SERVER}   ${BROWSER}

Type Username
    Input Text      ${NAME}user-name  ${USER}

Type Password
    Input Text      ${NAME}password   ${PASSWORD}

Login
    Click Button    ${NAME}login-button

Add item to cart
    Click Button    ${NAME}add-to-cart-sauce-labs-backpack

Open Cart
    Click Element   ${ID}shopping_cart_container

Checkout
    Click Element   ${ID}checkout

Name and Postal
    Input Text      ${NAME}firstName  Robot
    Input Text      ${NAME}lastName   Franework
    Input Text      ${NAME}postalCode   Testcase

Finish shopping
    Click Element   ${ID}continue
    Click Button    ${NAME}finish

Close
    Close Browser