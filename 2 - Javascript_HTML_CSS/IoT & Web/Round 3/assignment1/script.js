let number = 0;
const tableBody = document.getElementById("tablebody");
for (let i = 1; i <= 9; i++) {
  let row = document.createElement("tr");
  for (let j = 0; j <= 8; j++) {
    let cell = document.createElement("td");
    let cellText = document.createTextNode(i + j);
    cell.appendChild(cellText);
    row.appendChild(cell);
  }
  tableBody.appendChild(row);
}
