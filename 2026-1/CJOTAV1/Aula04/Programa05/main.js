import Cangaceiro from "./Cangaceiro.js";

console.log("\n=> Playing: The Calango Hunter \n");

const player = new Cangaceiro("Walter Paraíba", "peixeira", "Lampião", "calango");

player.callPet();
player.attack();
player.takeDamage(50);

console.log();