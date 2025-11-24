Caso você queira apenas rodar o jogo: baixe o game.exe, os arquivos .dll da pasta lib e os assets (ponha numa pasta com esse nome, ou eles não serão carregados no jogo).

Caso você queira modificar o jogo: baixe tudo MENOS o game.exe, que deve ser buildado em sua máquina conforme alterações forem sendo feitas (as instruções estão comentadas em main.cpp).
Além disso, baixe também a biblioteca Raylib através de seu instalador no itch.io, e quaisquer compiladores/extensões/etc. que sejam necessários para seu VS Code (ou sua IDE de preferência).

Note que, durante o processo de build, a pasta obj (com arquivos .o) será automaticamente criada para fins técnicos. Não inclua-a em repositórios; sinta-se livre para adicionar o caminho da pasta ao seu .gitignore se desejar por conveniência.

(*Adicionalmente, vale citar que este projeto foi feito com a ajuda do seguinte template: https://github.com/RobLoach/raylib-cpp/tree/master*)
