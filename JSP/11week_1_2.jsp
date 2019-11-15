<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
    </head>
    <body>
        <h1>로그인 입력 화면에서</h1>
        <p>전송된 아이디와 비밀번호는
        <b><%= request.getParameter("id") %> <%= request.getParameter("passw") %></b> 입니다.
        </p>
    </body>
</html>
