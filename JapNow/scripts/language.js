//<!--Authors: James Mok(Monday PM) Faizen Syed-->
var request;

function makeRequest() {
    request = new XMLHttpRequest();
    request.onreadystatechange = showResults;
    request.open("GET", "../languages.xml", true);
    request.send();

}
function showResults() {
    if (request.readyState === 4) {
        if (request.status === 200) {

            var table = document.getElementById("xmlTable");
            var doc = request.responseXML;
            var translations = doc.getElementsByTagName("translation");
            var column = 0;
            var rows = 0;
            var row = table.insertRow(rows);
            for (var i = 0; i < translations.length; i++) {
                if (column === 3) {
                    rows += 1;
                    row = table.insertRow(rows);
                    column = 0;
                }
                var cellInfo = row.insertCell(column);
                var english = translations.item(i).getElementsByTagName("english").item(0).textContent;
                var japanese = translations.item(i).getElementsByTagName("japanese").item(0).textContent;
                var transJap = "\"" + japanese+"\"";
                var romanji = translations.item(i).getElementsByTagName("romanji").item(0).textContent;
                //<td><a onclick="play('こんにちは');"><b>こんにちは</b><br><br>Hello</a></td>;;

                cellInfo.innerHTML = "<h4 style='text-align:center'>" + english + "</h4></centre>" + "<a href='#' onclick='play(" + transJap + "); return false;'><p style='text-align:center'>" 
                        + japanese + "<br><br>" + romanji + "</p></a>";
                column += 1;
            }

            console.log(request);
            console.log(request.responseXML);
        } else {
            console.log(request.statusText);
        }

    }
}