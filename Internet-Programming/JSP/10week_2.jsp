<!--

  if/else를 이용하여 day의 값에 따라 주말인지 아닌지 출력하는 프로그램
  여기에서는  day = 3 이라고 정의
  
-->

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%! int day = 3; %>
<html>
<head>
<meta charset="UTF-8">
<title>if/else 예제</title>
</head>

<body>
<% if(day == 1 | day == 7) { %>
	<p> 오늘은 주말입니다.</p>
<% } else { %>
	<p>오늘은 주말이 아닙니다.</p>
<% } %>
</body>
</html>
