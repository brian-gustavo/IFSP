<!DOCTYPE html>
<html lang="pt-br">
<head>
	<meta charset="UTF-8">
	<title>Formulário de tarefas</title>
</head>
<body>
	<h1>Adicionar nova tarefa</h1>
    <form action="task" method="post">
        <label for="description">Descrição:</label>
        <input type="text" id="description" name="description" required>
        <br>
        <label for="date">Data:</label>
        <input type="date" id="date" name="date" required>
        <br>
        <button type="submit">Adicionar</button>
    </form>
    <a href="task">Ver lista de tarefas</a>
</body>
</html>
