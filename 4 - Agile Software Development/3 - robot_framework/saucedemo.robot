*** Settings ***
Documentation   Robot Framework - Test automation
Library         Selenium2Library
Library         String

*** Variables ***
${SERVER}           https://www.saucedemo.com/
${BROWSER}          chrome
${USER}             performance_glitch_user
${PASSWORD}         secret_sauce
${NAME}             name=
${ID}               id=

*** Test Cases ***
Login
    Open Browser    ${SERVER}   ${BROWSER}
    Input Text      ${NAME}user-name  ${USER}
    Input Text      ${NAME}password   ${PASSWORD}
    Click Button    ${NAME}login-button

Add to Cart
    Click Button    ${NAME}add-to-cart-sauce-labs-backpack

Checkout
    Click Element   ${ID}shopping_cart_container
    Click Element   ${ID}checkout
    Input Text      ${NAME}firstName  Robot
    Input Text      ${NAME}lastName   Franework
    Input Text      ${NAME}postalCode   Testcase
    Click Element   ${ID}continue
    Click Button    ${NAME}finish

Close Browser
    Close Browser