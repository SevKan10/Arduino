var sheet_id = "1VuAY-GBnXjtkWjiGmpkCzqq9n0U1D2uJvPhxIFcw-Ac";
var sheet_name = "Data";
function doGet(e){
var ss = SpreadsheetApp.openById(sheet_id);
var sheet = ss.getSheetByName(sheet_name);
var sensor = Number(e.parameter.sensor);
var date = Number(e.parameter.date);
sheet.appendRow([sensor,date]);
}