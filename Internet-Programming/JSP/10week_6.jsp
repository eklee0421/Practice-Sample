<!--테이블에 1단부터 9단까지 출력하는 프로그램-->

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<% int num; %>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<table border="5">
	<thead><tr>
<% for(int a=1; a<10;a++) { 

	out.print("<th>" + a + "단</th>");
}
%>
</tr></thead>
<tbody>

<% for(int a=1; a<10; a++) { 
		out.print("<tr>");
		
		for(int b=1; b<10; b++) { 

			out.print("<td>" + b + "*" + a + "=" + b*a + "</td>");
		}
		
		out.print("</tr>");
	}
%>
</tbody>
</table>
</body>
</html>
