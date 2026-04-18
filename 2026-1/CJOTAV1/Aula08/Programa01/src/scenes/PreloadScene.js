import Phaser from 'phaser';

export default class PreloadScene extends Phaser.Scene {
    constructor() {
        super({key: 'PreloadScene'});
    }

    preload() {
        this.displayProgressBar();

        this.load.image('background', 'assets/images/background.png');
        this.load.image('fence', 'assets/images/cerca.png');
        this.load.image('player', 'assets/images/mineiro.png');

        this.load.image('cheese1', 'assets/images/queijo1.png');
        this.load.image('cheese2', 'assets/images/queijo2.png');
        this.load.image('cheese3', 'assets/images/queijo3.png');
        this.load.image('cheese4', 'assets/images/queijo4.png');
        this.load.image('cheese5', 'assets/images/queijo5.png');
    }

    create() {
        this.scene.start('GameScene');
    }

    displayProgressBar() {
        const {width, height} = this.cameras.main;

        const progressBarBg = this.add.graphics();
        progressBarBg.fillStyle(0x222222, 0.8);
        progressBarBg.fillRect(width / 4 - 2, height / 2 - 12, width / 2 + 4, 24);

        const progressBar = this.add.graphics();

        const loadingText = this.add.text(
            width / 2,
            height / 2 - 30,
            'Loading...',
            {
                fontSize: '20px',
                fill: '#ffffff'
            }
        ).setOrigin(0.5);

        this.load.on('progress', (value) => {
            progressBar.clear();
            progressBar.fillStyle(0xffffff, 1);
            progressBar.fillRect(width / 4 - 2, height / 2 - 10, (width / 2) * value, 20);
        });

        this.load.on('complete', () => {
            progressBar.destroy();
            progressBarBg.destroy();
            loadingText.destroy();
        });
    }
}