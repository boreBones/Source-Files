//<!--Authors: James Mok(Monday PM) Faizen Syed-->
var request;

function makeRequest(){
    request = new XMLHttpRequest();
    request.onreadystatechange = showResults;
    request.open("GET", "../attractions.xml", true);
    request.send();
    
}
function showResults(){
    if (request.readyState === 4){
        if (request.status === 200){
            
            var table = document.getElementById("xmlTable");
            var doc = request.responseXML;
            var attractions = doc.getElementsByTagName("attraction");
            
            for(var i=0; i<attractions.length;i++){
                var row = table.insertRow(i);
                var cellImg = row.insertCell(0);
                var cellInfo = row.insertCell(1);
                var imgSrc = attractions.item(i).getElementsByTagName("imgSrc").item(0).textContent;
                cellImg.innerHTML = "<img src='"+ imgSrc +"'/><br><p>from:google images</p>";
				var location = attractions.item(i).getElementsByTagName("location").item(0).textContent;
				var built = attractions.item(i).getElementsByTagName("built").item(0).textContent;
                var name = attractions.item(i).getElementsByTagName("name").item(0).textContent;
                cellInfo.innerHTML = "<h3 style='text-align:center'>"+ name + "</h3></centre>" + "<p style='text-align:left'><b>Location:</b> " + location + "<br><b>Built: </b> " + built + "</p><br>" + 
				attractions.item(i).getElementsByTagName("summary").item(0).textContent;
  
            }
            
            console.log(request);
            console.log(request.responseXML);
        } else {
            console.log(request.statusText);
        }
    }
}