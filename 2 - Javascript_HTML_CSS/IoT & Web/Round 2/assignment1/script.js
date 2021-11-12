const dropdownForm = document.getElementById("dropdownForm");
const dropdownButton = document.getElementById("typistysbtn");

const dropdownValueSpan = document.getElementById("dropdownvalue");
const typistettyTeksti = document.getElementById("typistettyTxt");

dropdownButton.addEventListener("click", () => {
  console.log("click");
  const selectedValue = dropdownForm.dropdownNmbrs.value;
  dropdownValueSpan.textContent = selectedValue;

  const getMyText = document.getElementById("txtArea");
  const typistettäväTeksti = getMyText.value;
  //console.log(selectedValue)
  const slicedTxt = typistettäväTeksti.slice(0, -selectedValue);

  typistettyTeksti.textContent = slicedTxt;
  //console.log(typeof typistettäväTeksti);
  //console.log(typistettäväTeksti);
  console.log(slicedTxt);
  //console.log
});
