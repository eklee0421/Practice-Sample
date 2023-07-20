<!--for문을 이용하여 글자의 크기를 점점 크게 출력하는 -->

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%! int fontSize; %>
<html>
<head>
<meta charset="UTF-8">
<title>반복 구조 예제</title>
</head>
<body>
<% for (fontSize = 1; fontSize <= 6; fontSize++){ %>
	<font color="red" size="<%=fontSize %>">
	안녕하세요?
	</font><br/>
<% } %>
</body>
</html>
