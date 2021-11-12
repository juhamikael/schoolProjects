//Buttons
const startTimerButton = document.getElementById("starttimerbtn");
const pauseTimerButton = document.getElementById("pausetimerbtn");
const resetTimerButton = document.getElementById("resettimerbtn");

//Muuttujat ajalle
const seconds_html = document.getElementById("seconds");
const minutes_html = document.getElementById("minutes");
const hours_html = document.getElementById("hours");

myTimer = setInterval(timer, 1000);

let isCounterIncreasing = false;
let seconds = 0;
let secondsString = "00";
let minutes = 0;
let minutesString = "00";
let hours = 0;
let hoursString = "00";

function timer() {
  console.log("Tick");
  if (isCounterIncreasing) {
    seconds++;
    if (seconds >= 60) {
      minutes++;
      seconds = 0;
    }
    if (minutes >= 60) {
      hours++;
      minutes = 0;
    }
  }
  //console.log("counter", seconds);
  //console.log("counter", minutes);
  //console.log("counter", hours);
  seconds_html.textContent = seconds;
  minutes_html.textContent = minutes;
  hours_html.textContent = hours;
}

startTimerButton.addEventListener("click", () => {
  console.log("Clicked startTimerButton");
  isCounterIncreasing = true;
});
pauseTimerButton.addEventListener("click", () => {
  console.log("Clicked pauseTimerButton");
  isCounterIncreasing = false;
});
resetTimerButton.addEventListener("click", () => {
  console.log("Clicked resetTimerButton");
  isCounterIncreasing = false;
  seconds = 0;
  minutes = 0;
  hours = 0;
});

//if sth

/*


  if (seconds < 10 , minutes < 10, hours < 10) {
    secondsString = "0" + seconds.toString();
    minutesString = "0" + minutes.toString();
    hoursString = "0" + hours.toString();
    seconds_html.textContent = secondsString;
    minutes_html.textContent = minutesString;
    hours_html.textContent = hoursString;
  } else {
    seconds_html.textContent = seconds;
    minutes_html.textContent = minutes;
    hours_html.textContent = hours;
  }

else if (minutes < 10) {
    minutesString = "0" + minutes.toString();
    minutes_html.textContent = minutesString;
  } 
  else if (hours < 10) {
    hoursString = "0" + hours.toString();
    hours_html.textContent = hoursString;
  }
    else {
    seconds_html.textContent = seconds;
    minutes_html.textContent = minutes;
    hours_html.textContent = hours;
  }


  if (seconds < 10) {
    secondsString = "0" + seconds.toString();
  } else if (minutes < 10) {
    minutesString = "0" + minutes.toString();
  } else if (hours < 10) {
    hoursString = "0" + hours.toString();
  } else {
    secondsString = seconds;
    minutesString = minutes;
    hoursString = hours;
  }






resettimerButton.addEventListener("click", () => {
    console.log("Clicked pauseTimerButton");
    isCounterIncreasing = false;
});
   */
/*
const something = '5'
const somethingAsNumber = Number(something)
*/
/*
  if (seconds > 59){
    minutes++;
    seconds = 0;
    }   if (minutes == 60)
    hours++;
    minutes = 0;

*/
