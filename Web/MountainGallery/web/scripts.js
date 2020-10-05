class Mountain {
    constructor(id, name, height, description) {
        this.id = id;
        this.name = name;
        this.height = height;
        this.description = description;
    }
    toGet = () => {
        return "id=" + this.id + "&name=" + this.name + "&height=" + this.height + "&description=" + this.description;
    }
    addToTable = () => {
        let table = document.getElementById("tableMountains");
        let row = table.insertRow();
        row.insertCell().innerHTML = this.id;
        row.insertCell().innerHTML = this.name;
        row.insertCell().innerHTML = this.height;
        row.insertCell().innerHTML = "<a href='#' class='btn btn-secondary' role='button' onclick='getDetails(" + this.id + ");'>Watch details</a>";
    }
}
function getDetails(mountainID) {
    // Ask servlet to return the elements of the specified mountain and add it to the paragraphs
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "GalleryGet?id=" + mountainID, true);
    xhttp.responseType = "json";
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            moutain_obj = this.response;
            document.getElementById("mountain_id_details").innerHTML = "Moutain ID: " + moutain_obj.ID;
            document.getElementById("mountain_name_details").innerHTML = moutain_obj.Name;
            document.getElementById("mountain_height_details").innerHTML = "Height: " + moutain_obj.Height;
            document.getElementById("mountain_description_details").innerHTML = "Description: " + moutain_obj.Description;
            getLastVisited();
        }
    };
    xhttp.send();
}
function getLastVisited() {
    // Get from servlet last visited elements and add buttons with their ids
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "GetLastVisited", true);
    xhttp.responseType = "json";
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            var html_code = "<div class='list-group'>";
            moutain_obj = this.response; // Contains a element list with inside an array
            for (i = 0; i < 5; i++) {
                if (moutain_obj.list[i]) { // If is defined
                    html_code += "<a href='#' class='list-group-item list-group-item-action' onclick='getDetails(" + moutain_obj.list[i] + ")'>Watch again N" + moutain_obj.list[i] + "</a>"
                }
            }
            html_code += "</div>";
            document.getElementById("last_visited_div").innerHTML = html_code;
        }
    };
    xhttp.send();
}
function addObject() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("POST", "GalleryAdd", true);
    xhttp.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            if (this.response.includes('true')) { // If query had no errors
                mountain.addToTable();
            } else {
                console.log("Writing in paragrapg");
                document.getElementById("adding_error").innerHTML = "Error in adding data";
            }
        }
    }
    let id = document.getElementById("mountain_id_input").value;
    let name = document.getElementById("mountain_name_input").value;
    let height = document.getElementById("mountain_heigh_input").value;
    let description = document.getElementById("mountain_description_input").value;
    let mountain = new Mountain(id, name, height, description);
    xhttp.send(mountain.toGet());
}
