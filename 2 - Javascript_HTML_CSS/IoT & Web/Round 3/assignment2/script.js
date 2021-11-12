const tableBody = document.getElementById("tablebody");
const dropdownForm = document.getElementById("dropdownForm");
const dropdownButton = document.getElementById("selectbtn");
console.log("button clicked");
dropdownButton.addEventListener("click", () => {
  const selectedValue = dropdownForm.dropDownItems.value;
  let countryName;
  if (selectedValue == "fi") {
    countryName = "Finland";
  } else if (selectedValue == "is") {
    countryName = "Iceland";
  } else if (selectedValue == "no") {
    countryName = "Norway";
  } else if (selectedValue == "se") {
    countryName = "Sweden";
  } else if (selectedValue == "dk") {
    countryName = "Denmark";
  }
  const myAsyncFunction = async () => {
    const response = await fetch(
      `https://corona-api.com/countries/${selectedValue}`
    );
    //console.log("Response: ", response);
    const data = await response.json();
    console.log("data: ", data);
    // Generate html rows for table
    tableBody.textContent = "";
    data.data.timeline.forEach((singleDay, index) => {
      if (index < 28) {
        console.log(singleDay);
        const row = document.createElement("tr");
        const cellDataArray = [
          index + 1, // Hashtag
          singleDay.date, // Date
          singleDay.new_confirmed, // Confirmed
          singleDay.new_recovered, // Recovered
          singleDay.new_deaths, // Deaths
        ];
        for (cellData of cellDataArray) {
          const cell = document.createElement("td");
          const cellText = document.createTextNode(cellData);
          cell.appendChild(cellText);
          row.appendChild(cell);
        }

        tableBody.appendChild(row);
      }
    });
  };
  myAsyncFunction();
});
