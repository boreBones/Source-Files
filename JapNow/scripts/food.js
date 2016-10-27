var request;

function makeRequest() {
    request = new XMLHttpRequest();
    request.onreadystatechange = showResults;
    request.open("GET", "../foods.xml", true);
    request.send();

}
function showResults() {
    if (request.readyState === 4) {
        if (request.status === 200) {

            var table = document.getElementById("xmlTable");
            var doc = request.responseXML;
            var foods = doc.getElementsByTagName("food");

            for (var i = 0; i < foods.length; i++) {
                var row = table.insertRow(i);
                var cellImg = row.insertCell(0);
                var cellInfo = row.insertCell(1);
                var imgSrc = foods.item(i).getElementsByTagName("imgSrc").item(0).textContent;
                cellImg.innerHTML = "<img src='" + imgSrc + "'/><br><p>from:google images</p>";
                var meat = foods.item(i).getElementsByTagName("meat").item(0).textContent;
                var name = foods.item(i).getElementsByTagName("name").item(0).textContent;
                cellInfo.innerHTML = "<h3 style='text-align:center'>" + name + "</h3></centre>" + "<p style='text-align:left'><b>Meats:</b> " + meat + "</p><br>" +
                        foods.item(i).getElementsByTagName("description").item(0).textContent;

            }

            console.log(request);
            console.log(request.responseXML);
        } else {
            console.log(request.statusText);
        }
    }
}

