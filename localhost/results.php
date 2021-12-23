<?php
    $TypeGraph = $_POST["groupTypeGraph"];
    $n_vertex = intval($_POST["number_vertex"]);
    $n_arcs = intval($_POST["number_arcs"]);
    $TypeTask = $_POST["groupTypeTask"];

    $cmd = "C:/localhost/algorithm/algorithm.exe ";
    $cmd .= $TypeGraph . " " . $n_vertex . " " . $n_arcs . " " . $TypeTask;
    
    system($cmd);

    $cmd_picture = "Graphviz\\bin\\dot graph.dot -Tpng -opath.png";
    system($cmd_picture);
    
    $len = file_get_contents("len.txt");
?>


<!DOCTYPE HTML>
<html>
    <head>
        <title>Графы lab3</title>
        <meta charset="utf-8">
        <link rel="stylesheet" href="style.css">
    </head>
    <body>
        <center><h1>Алгоритмы на графах</h1>
        <h3>Лабораторная работа №3</h3>

        <center><div class="button-container">
            <a href="http://localhost/task.html" class="double-border-button">Назад</a>
        </div></center>

        <h2>Граф:</h2>
	<img src="path.png" alt="Graph with path">

	<h2><?php if ($TypeTask == "BestPath") echo "Длина кратчайшего пути"; else echo "Hаибольшая пропускная способность";?>:</h2>
	<p><?php echo $len; ?></p>
        
        <center><div class="button-container">
            <a href="http://localhost/task.html" class="double-border-button">Назад</a>
        </div></center>
    </body>
</html>