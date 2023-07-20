<!--
1에서 10까지의 수와 그의 제곱을 각각 출력하는 프로그램
-->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<% 
for (int i = 1; i <= 10 ; i++){
	out.print(i + " ");
 } %>
<br/>
<% for (int j = 1; j <= 10; j++){
	out.print(j * j + " ");
} %>

</body>
</html>
