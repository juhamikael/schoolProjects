const lang = "fi";
const key = "KEY_HIDDEN";
const https = "https://";

export const cityName = "Tampere";
const current = `${https}api.openweathermap.org/data/2.5/weather?q=${cityName}&lang=${lang}&appid=${key}&units=metric`;
const currentResponse = await fetch(`${current}`);
const data = await currentResponse.json();
export const country = data.sys.country;
const lon = data.coord.lon;
const lat = data.coord.lat;
export const address = `https://api.openweathermap.org/data/2.5/onecall?lat=${lat}&lon=${lon}&exclude=minutely,hourly&appid=${key}&units=metric`;
