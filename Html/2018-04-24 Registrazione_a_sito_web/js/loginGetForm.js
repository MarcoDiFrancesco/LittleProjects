$(document).ready(function() {
  $("#loginSubmit").click(function() {
    $("#loginSubmit").hide();
    $("#loginMessage").html("<img src='images/loading2.gif' style='width: 50px'>");

    var username = $("#username").val();
    var password = $("#password").val();

    $.post("php/login.php", { username: username, password:password })
    .done(function(data){
      if (data == "success") {
        alert('connectd');
        window.location = "../index.html";
      } else {
        $("#loginMessage").text("Invalid username or password");
        $("#loginSubmit").show();
      }
    });
  });
});