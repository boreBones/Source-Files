//<!--Authors: James Mok(Monday PM) Faizen Syed-->
var request;

function makeRequest() {
    request = new XMLHttpRequest();
    request.onreadystatechange = showResults;
    request.open("GET", "../animes.xml", true);
    request.send();

}
function showResults() {
    if (request.readyState === 4) {
        if (request.status === 200) {

            var table = document.getElementById("xmlTable");
            var doc = request.responseXML;
            var episodes = doc.getElementsByTagName("anime");

            for (var i = 0; i < episodes.length; i++) {
                var row = table.insertRow(i);
                var cellImg = row.insertCell(0);
                var cellInfo = row.insertCell(1);
                var imgSrc = episodes.item(i).getElementsByTagName("imgSrc").item(0).textContent;
                cellImg.innerHTML = "<img src='" + imgSrc + "'/><br><p>from:google images</p>";
                var totalEpisodes = episodes.item(i).getElementsByTagName("totalEpisodes").item(0).textContent;
                var types = episodes.item(i).getElementsByTagName("genre").item(0).textContent;
                var title = episodes.item(i).getElementsByTagName("title").item(0).textContent;
                cellInfo.innerHTML = "<h3 style='text-align:center'>" + title + "</h3></centre>" + "<p style='text-align:left'><b>Total Episodes:</b> " + totalEpisodes + "<br><b>Genre: </b> " + types + "</p><br>" +
                        episodes.item(i).getElementsByTagName("summary").item(0).textContent;

            }

            console.log(request);
            console.log(request.responseXML);
        } else {
            console.log(request.statusText);
        }
    }
}