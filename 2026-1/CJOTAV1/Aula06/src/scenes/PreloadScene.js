import Phaser from 'phaser';

export default class PreloadScene extends Phaser.Scene {
    constructor() {
        super({key: 'PreloadScene'});
    }

    preload() {
        this.displayProgressBar();

        this.load.image('cenario', 'assets/images/background.png');
        this.load.image('player', 'assets/images/garota.png');
        this.load.image('caixa', 'assets/images/caixa_remedio.png');
        this.load.image('cartela', 'assets/images/cartela_remedio.png');

        this.load.audio('soundtrack', 'assets/music/soundtrack.mp3');
        this.load.audio('collect', 'assets/sounds/collect_item.mp3');
    }

    create() {
        this.loadCustomFont().then(() => {
            this.scene.start('GameScene');
        });
    }

    loadCustomFont() {
        const font = new FontFace('Pixelta', 'url(assets/fonts/pixelta.ttf)');

        return font.load()
            .then((loadedFont) => {
                document.fonts.add(loadedFont);
            })
            .catch((err) => {
                console.error('Erro ao carregar a fonte Pixelta:', err);
            });
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