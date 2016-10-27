//<!--Authors: James Mok(Monday PM) Faizen Syed-->
function showHide(id) {
    var thing = document.getElementById(id);
    if (thing.className === "show") {
        thing.className = "hide";
    } else {
        thing.className = "show";
    }
}

function mouseOver(id){
	var thisEle = document.getElementById(id);
	thisEle.style.background= "#FD6769";
}
function mouseOut(id){
var thisEle = document.getElementById(id);
	thisEle.style.background= "#000000";
}
