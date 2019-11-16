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
	<h1>성별과 좋아하는 과목 조사</h1>
	<form action="4.jsp" method="post">
	1. 성별을 선택하세요.[Radio버튼]<br>
	<input type="radio" name="gender" value="남자"> 남자 
	<input type="radio" name=gender value="여자"> 여자<br>
	<br><br>
	2. 좋아하는 과목을 선택하세요.[Checkbox]
	<input type="checkbox" name="subject" value="SQL응용"> SQL응용<br>
	<input type="checkbox" name="subject" value="DB개발도구"> DB개발도구<br>
	<input type="checkbox" name="subject" value="JSP"> JSP<br>
	<input type="checkbox" name="subject" value="오라클실무"> 오라클실무<br>
	<input type="checkbox" name="subject" value="SQL응용"> SQL응용<br>
	<br>
	<input type = "submit" value="확인">
	<input type = "reset" value="취소">
	
	</form>
</body>
</html>
