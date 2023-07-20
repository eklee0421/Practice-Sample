<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%
    // 인코딩
    request.setCharacterEncoding("UTF-8");
%>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<h1>성별과 좋아하는 과목은</h1>
<% 
String gender= request.getParameter("gender");
String[] checked=request.getParameterValues("subject");//그룹 이름으로 받음. 체크된 항목이 배열의 형태로 그룹화 되어 전달
%>
당신은 <b><%=gender%></b>이고,
<br>좋아하는 과목으로
<br>
<b>
<% for (int i=0; i<checked.length; i++) {%>
<%="-"%>
<%=checked[i]%><br>
<%}%>
</b>
<br>
을 선택하였군요.

</body>
</html>
