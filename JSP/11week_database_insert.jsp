<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>

<!--나의 데이터 베이스-->
<!-- The core Firebase JS SDK is always required and must be listed first -->
<script src="https://www.gstatic.com/firebasejs/7.5.0/firebase-app.js"></script>

<!-- TODO: Add SDKs for Firebase products that you want to use
     https://firebase.google.com/docs/web/setup#available-libraries -->

<script src="https://www.gstatic.com/firebasejs/7.5.0/firebase-analytics.js"></script>
<script src="https://www.gstatic.com/firebasejs/3.1.0/firebase-auth.js"></script>
<script src="https://www.gstatic.com/firebasejs/3.1.0/firebase-database.js"></script>

<script>
  // Your web app's Firebase configuration
  var firebaseConfig = {
    apiKey: "AIzaSyCDwfwiLUdjlTB2oSzbeiHtziOvB6qbOKM",
    authDomain: "interprogram-b31ef.firebaseapp.com",
    databaseURL: "https://interprogram-b31ef.firebaseio.com",
    projectId: "interprogram-b31ef",
    storageBucket: "interprogram-b31ef.appspot.com",
    messagingSenderId: "712218173871",
    appId: "1:712218173871:web:95d606a79444042f0e4f5a"
  };

 // Initialize Firebase
firebase.initializeApp(firebaseConfig);
firebase.analytics();
<!--여기까지 데이터베이스 정보-->
 
function show(){
document.write("<table border = '1'>");
document.write("<tr> <td>user <td> email <td> user name");
var users_ref = firebase.database().ref('/users/');
users_ref.on('value', function(snapshot){ // a list of users
snapshot.forEach(function(childSnapshot){
var user_key = childSnapshot.key;
document.write("<tr> <td>" + user_key);
var user_ref = firebase.database().ref('/users/'+user_key + '/');
user_ref.once('value', function(snapshot2) { // a user
 snapshot2.forEach(function(childSnapshot2){ // attributes of the user
 document.write("<td>" + childSnapshot2.val() );
 });
});
});
});
 }
//Get a reference to the database service
var database = firebase.database();
function writeUserData(userId, name, email) {
 firebase.database().ref('users/' + userId).set({
 userName: name,
 email: email
 });
}
function add(){
var userID = document.getElementById('userID').value;
var email = document.getElementById('email').value;
var userName = document.getElementById('userName').value;
if(userID == '' || email == '' || userName == ''){
alert("Fill inputs before clicking ADD button");
return ;
}
writeUserData(userID, userName, email);
alert('add user info successfully.');
}
</script>

<body>
<div><button onclick = "show()">show</button></div>
<br>
userID: <input id='userID' value=''/><br>
email: <input id='email' value=''/><br>
userName: <input id='userName' value=''/><br>
<div><button onclick = "add()">add</button></div>
</body>
</html>
