import Phaser from 'phaser';

import PreloadScene from './scenes/PreloadScene.js';
import GameScene from './scenes/GameScene.js';

const WIDTH = 1000;
const HEIGHT = 700;

const SHARED_CONFIG = {
    width: WIDTH,
    height: HEIGHT,
    debug: false
}

const SCENES = [PreloadScene, GameScene];

const config = {
    type: Phaser.AUTO,
    ...SHARED_CONFIG,
    backgroundColor: '#0080ff',
    parent: 'game-container',
    pixelArt: false,
    physics: {
        default: 'arcade',
        arcade: {
            gravity: {y: 300},
            debug: SHARED_CONFIG.debug,
        }
    },
    scale: {
        mode: Phaser.Scale.FIT,
        autoCenter: Phaser.Scale.CENTER_BOTH 
    },
    scene: SCENES 
};

new Phaser.Game(config);