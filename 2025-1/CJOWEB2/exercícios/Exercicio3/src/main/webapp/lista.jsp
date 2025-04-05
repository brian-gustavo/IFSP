<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

<!DOCTYPE html>
<html lang="pt-br">
<head>
	<meta charset="UTF-8">
	<title>Lista das tarefas atuais</title>
</head>
<body>
	<h1>Lista de tarefas</h1>
    <table border="1">
        <tr>
            <th>ID</th>
            <th>Descrição</th>
            <th>Data</th>
        </tr>
        <c:forEach var="task" items="${tasks}">
            <tr>
                <td>${task.id}</td>
                <td>${task.description}</td>
                <td>${task.date}</td>
            </tr>
        </c:forEach>
    </table>
    <a href="formulario.jsp">Adicionar nova tarefa</a>
</body>
</html>
