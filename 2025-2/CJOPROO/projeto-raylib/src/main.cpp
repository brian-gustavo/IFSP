// Para buildar e rodar o jogo, deve-se usar o comando "mingw32-make" seguido de ".\game.exe"

#define RAYGUI_IMPLEMENTATION

#include "raygui/raygui.h"
#include "raylib.h"

#include <string>
#include <iostream>
#include <cmath>
#include <fstream> 
#include <sstream> 
#include <vector>
#include <algorithm>

const int screenWidth = 1200; 
const int screenHeight = 800;
const char* windowTitle = "Brasidle";

const int upgradeColumnWidth = screenWidth * 0.3; 
const int gameAreaLimitX = screenWidth - upgradeColumnWidth; 
const char* SAVE_FILE_NAME = "savegame.dat";

const Color BRAZIL_GREEN = { 0, 151, 57, 255 }; 
const Color BRAZIL_YELLOW = { 254, 223, 0, 255 }; 
const Color TEXT_ON_GREEN = { 255, 255, 255, 255 };
const Color TEXT_ON_YELLOW = { 0, 100, 0, 255 };

struct FloatingText {
    Vector2 position;
    float lifeTime;
    Color color;
    long long value;
};

std::vector<FloatingText> floatingTexts;

long long dinheiro = 0;
float dinheiroPorSegundo = 0.0f;
float dinheiroAcumulado = 0.0f;

const int BOLO_DE_POTE_CUSTO = 100;
bool hasBoloDePote = false; 

const int UBER_CUSTO = 500; 
bool hasUber = false;        

const int HOTMART_CUSTO = 1000;
bool hasHotmart = false; 

const int TIGRINHO_CUSTO = 2000;
bool hasTigrinho = false; 

const int SITE_APOSTA_CUSTO = 100000;
bool hasSiteAposta = false;

long long clickValue = 1;
float moedaScale = 1.0f;
const float SCALE_DOWN_VALUE = 0.7f;
const float SCALE_SPEED = 8.0f;

bool isMusicPlaying = true; 
Texture2D soundOnTexture;
Texture2D soundOffTexture;

bool DrawUpgradeCard(Rectangle bounds, const char* title, int cost, const char* description, bool canAfford) {
    GuiPanel(bounds, NULL);

    Rectangle buttonRect = {bounds.x + 5, bounds.y + 5, bounds.width - 10, bounds.height - 25};
            
    bool pressed = GuiButton(buttonRect, TextFormat("%s (R$%d)", title, cost));
            
    int descY = (int)bounds.y + (int)bounds.height - 20;
    Color descColor = canAfford ? TEXT_ON_YELLOW : Fade(TEXT_ON_YELLOW, 0.5f);
    DrawText(description, (int)bounds.x + 8, descY, 12, descColor);
            
    if (!canAfford) {
        DrawRectangleRec(bounds, Fade(RED, 0.2f));
    }

    return pressed;
}

void SaveGame() {
    std::stringstream ss;
    ss << "{\n";
    ss << "\"dinheiro\":" << dinheiro << ",\n";
    ss << "\"dinheiroPorSegundo\":" << dinheiroPorSegundo << ",\n";
    ss << "\"hasBoloDePote\":" << (hasBoloDePote ? "true" : "false") << ",\n";
    ss << "\"hasUber\":" << (hasUber ? "true" : "false") << ",\n";
    ss << "\"hasHotmart\":" << (hasHotmart ? "true" : "false") << ",\n";
    ss << "\"hasTigrinho\":" << (hasTigrinho ? "true" : "false") << ",\n";
    ss << "\"hasSiteAposta\":" << (hasSiteAposta ? "true" : "false") << ",\n";
    ss << "\"clickValue\":" << clickValue << "\n";
    ss << "}";

    SaveFileText(SAVE_FILE_NAME, (char*)ss.str().c_str());

    std::cout << "Jogo salvo com sucesso.\n";
}

void LoadGame() {
    if (!FileExists(SAVE_FILE_NAME)) {
        std::cout << "Arquivo de save não encontrado. Iniciando novo jogo.\n";
        return; 
    }

    char* fileText = LoadFileText(SAVE_FILE_NAME);

    if (fileText == NULL) {
        std::cout << "Erro ao ler arquivo de save.\n";
        return;
    }
    
    std::string content(fileText);
    
    try {
        size_t pos;

        pos = content.find("\"dinheiro\":");
        if (pos != std::string::npos) {
            std::string val = content.substr(pos + 11);
            dinheiro = std::stoll(val.substr(0, val.find(',')));
        }

        pos = content.find("\"dinheiroPorSegundo\":");
        if (pos != std::string::npos) {
            std::string val = content.substr(pos + 21);
            dinheiroPorSegundo = std::stof(val.substr(0, val.find(',')));
        }

        pos = content.find("\"hasBoloDePote\":");
        if (pos != std::string::npos) {
            std::string val = content.substr(pos + 16);
            hasBoloDePote = (val.substr(0, val.find(',')) == "true");
        }

        pos = content.find("\"hasUber\":");
        if (pos != std::string::npos) {
            std::string val = content.substr(pos + 10);
            hasUber = (val.substr(0, val.find(',')) == "true");
        }

        pos = content.find("\"hasHotmart\":");
        if (pos != std::string::npos) {
            std::string val = content.substr(pos + 13);
            hasHotmart = (val.substr(0, val.find(',')) == "true");
        }

        pos = content.find("\"hasTigrinho\":");
        if (pos != std::string::npos) {
            std::string val = content.substr(pos + 14);
            hasTigrinho = (val.substr(0, val.find(',')) == "true");
        }

        pos = content.find("\"hasSiteAposta\":");
        if (pos != std::string::npos) {
            std::string val = content.substr(pos + 16);
            hasSiteAposta = (val.substr(0, val.find(',')) == "true");
        }

        pos = content.find("\"clickValue\":");
        if (pos != std::string::npos) {
            std::string val = content.substr(pos + 13);
            clickValue = std::stoll(val.substr(0, val.find('}')));
        }
        
        std::cout << "Jogo carregado com sucesso. Dinheiro: R$" << dinheiro << " | DPS: " << dinheiroPorSegundo << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro ao analisar o savegame: " << e.what() << ". Iniciando novo jogo.\n";

        dinheiro = 0;
        dinheiroPorSegundo = 0.0f;
        hasBoloDePote = false;
        hasUber = false;
        hasHotmart = false;
        hasTigrinho = false;
        hasSiteAposta = false;
        clickValue = 1;
    }

    UnloadFileText(fileText);
}

int main() {
    LoadGame(); 
    
    InitAudioDevice();

    InitWindow(screenWidth, screenHeight, windowTitle);

    GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, ColorToInt(BLACK));
    GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, ColorToInt(WHITE)); 
    GuiSetStyle(DEFAULT, BORDER_COLOR_NORMAL, ColorToInt(TEXT_ON_YELLOW));

    Texture2D moeda = LoadTexture("assets/moeda.png");

    soundOnTexture = LoadTexture("assets/sound_on.png");
    soundOffTexture = LoadTexture("assets/sound_off.png");

    Music backgroundMusic = LoadMusicStream("assets/boateazul8bit.mp3");
    PlayMusicStream(backgroundMusic);
    SetMusicVolume(backgroundMusic, 0.5f);

    SetTargetFPS(60); 

    Rectangle clickableArea = { 
        (float)gameAreaLimitX / 2 - (float)moeda.width / 2,
        (float)screenHeight / 2 - (float)moeda.height / 2, 
        (float)moeda.width, 
        (float)moeda.height 
    };

    Rectangle boloDePoteRect = { (float)gameAreaLimitX + 20, (float)50, (float)upgradeColumnWidth - 40, (float)70 };
    Rectangle uberRect = { (float)gameAreaLimitX + 20, (float)50 + 70 + 10, (float)upgradeColumnWidth - 40, (float)70 };
    Rectangle hotmartRect = { (float)gameAreaLimitX + 20, (float)50 + 70*2 + 20, (float)upgradeColumnWidth - 40, (float)70 };
    Rectangle tigrinhoRect = { (float)gameAreaLimitX + 20, (float)50 + 70*3 + 30, (float)upgradeColumnWidth - 40, (float)70 };
    Rectangle siteApostaRect = { (float)gameAreaLimitX + 20, (float)50 + 70*4 + 40, (float)upgradeColumnWidth - 40, (float)70 };

    while (!WindowShouldClose()) {
        UpdateMusicStream(backgroundMusic);

        Rectangle muteButtonRec = { 
            (float)gameAreaLimitX - 50,
            10.0f,                      
            40.0f,                      
            40.0f                       
        };

        if (CheckCollisionPointRec(GetMousePosition(), muteButtonRec)) {
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                isMusicPlaying = !isMusicPlaying;

                if (isMusicPlaying) {
                    ResumeMusicStream(backgroundMusic);
                } else {
                    PauseMusicStream(backgroundMusic);
                }
            }
        }

        float centerX = clickableArea.x + clickableArea.width / 2.0f;
        float centerY = clickableArea.y + clickableArea.height / 2.0f;
        float radius = clickableArea.width / 2.0f;

        if (CheckCollisionPointCircle(GetMousePosition(), (Vector2){centerX, centerY}, radius)) {
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                dinheiro += clickValue;

                moedaScale = SCALE_DOWN_VALUE;

                FloatingText newText = {};

                newText.position.x = clickableArea.x + clickableArea.width / 2.0f;
                newText.position.y = clickableArea.y + clickableArea.height / 2.0f;
                newText.lifeTime = 0.8f;
                newText.color = TEXT_ON_GREEN; 
                newText.value = clickValue;

                floatingTexts.push_back(newText);
            }
        }

        dinheiroAcumulado += dinheiroPorSegundo * GetFrameTime();
        
        if (dinheiroAcumulado >= 1.0f) {
            long long transferAmount = (long long)floor(dinheiroAcumulado);
            dinheiro += transferAmount; 
            dinheiroAcumulado -= transferAmount;
        }

        if (moedaScale < 1.0f) {
            moedaScale += SCALE_SPEED * GetFrameTime();
            if (moedaScale > 1.0f) {
                moedaScale = 1.0f;
            }
        }

        float dt = GetFrameTime();
        
        for (size_t i = 0; i < floatingTexts.size(); ++i) {
            floatingTexts[i].position.y -= 30.0f * dt;
            floatingTexts[i].lifeTime -= dt;
        }

        floatingTexts.erase(
            std::remove_if(floatingTexts.begin(), floatingTexts.end(), 
                           [](const FloatingText& t){ return t.lifeTime <= 0.0f; }),
            floatingTexts.end()
        );

        BeginDrawing();

        DrawRectangle(0, 0, gameAreaLimitX, screenHeight, BRAZIL_GREEN);
        DrawRectangle(gameAreaLimitX, 0, upgradeColumnWidth, screenHeight, BRAZIL_YELLOW);
        DrawLine(gameAreaLimitX, 0, gameAreaLimitX, screenHeight, Fade(BLACK, 0.5f));

        Texture2D currentTexture = isMusicPlaying ? soundOnTexture : soundOffTexture;
    
        DrawTexturePro(
            currentTexture,
            (Rectangle){ 0.0f, 0.0f, (float)currentTexture.width, (float)currentTexture.height },
            muteButtonRec,
            (Vector2){ 0.0f, 0.0f },
            0.0f,
            WHITE
        );
        
        float scaledWidth = moeda.width * moedaScale;
        float scaledHeight = moeda.height * moedaScale;

        float drawX = centerX - (scaledWidth / 2.0f);
        float drawY = centerY - (scaledHeight / 2.0f);

        Rectangle destRecManual = { 
            drawX, drawY, 
            scaledWidth, 
            scaledHeight 
        };

        Rectangle sourceRec = { 
            0.0f, 0.0f, 
            (float)moeda.width, 
            (float)moeda.height 
        };

        DrawTexturePro(
            moeda,
            sourceRec,
            destRecManual,
            (Vector2){ 0.0f, 0.0f },
            0.0f,
            TEXT_ON_GREEN
        );

        for (const auto& text : floatingTexts) {
            float alpha = text.lifeTime / 0.8f;
            Color drawColor = Fade(text.color, alpha);
            
            std::string clickText = "+" + std::to_string(clickValue);
            const char* clickTextC = clickText.c_str();

            DrawText(clickTextC, (int)text.position.x - MeasureText(clickTextC, 20) / 2, (int)text.position.y, 20, drawColor);
        }

        if (!hasBoloDePote) {
            bool canAfford = (dinheiro >= BOLO_DE_POTE_CUSTO);
            if (DrawUpgradeCard(boloDePoteRect, "Vender bolo de pote", BOLO_DE_POTE_CUSTO, "+R$1 por segundo", canAfford)) {
                if (canAfford) {
                    dinheiro -= BOLO_DE_POTE_CUSTO; 
                    dinheiroPorSegundo += 1.0f;
                    hasBoloDePote = true; 
                }
            }
        }
        
        if (hasBoloDePote && !hasUber) {
            bool canAfford = (dinheiro >= UBER_CUSTO);
            if (DrawUpgradeCard(uberRect, "Trabalhar de Uber", UBER_CUSTO, "+R$10 por segundo", canAfford)) {
                if (canAfford) {
                    dinheiro -= UBER_CUSTO; 
                    dinheiroPorSegundo += 10.0f;
                    hasUber = true; 
                }
            }
        }

        if (hasUber && !hasHotmart) {
            bool canAfford = (dinheiro >= HOTMART_CUSTO);
            if (DrawUpgradeCard(hotmartRect, "Fazer curso na Hotmart", HOTMART_CUSTO, "Clique ganha R$5", canAfford)) {
                if (canAfford) {
                    dinheiro -= HOTMART_CUSTO; 
                    clickValue = 5;
                    hasHotmart = true; 
                }
            }
        }

        if (hasUber && !hasTigrinho) {
            bool canAfford = (dinheiro >= TIGRINHO_CUSTO);
            if (DrawUpgradeCard(tigrinhoRect, "Postar propaganda de tigrinho", TIGRINHO_CUSTO, "+R$25 por segundo", canAfford)) {
                if (canAfford) {
                    dinheiro -= TIGRINHO_CUSTO; 
                    dinheiroPorSegundo += 25.0f; 
                    hasTigrinho = true; 
                }
            }
        }
        
        if (hasHotmart && hasTigrinho && !hasSiteAposta) {
            bool canAfford = (dinheiro >= SITE_APOSTA_CUSTO);
            if (DrawUpgradeCard(siteApostaRect, "Criar site de aposta esportiva", SITE_APOSTA_CUSTO, "+R$1000 por segundo", canAfford)) {
                if (canAfford) {
                    dinheiro -= SITE_APOSTA_CUSTO; 
                    dinheiroPorSegundo += 1000.0f; 
                    hasSiteAposta = true; 
                }
            }
        }

        if (hasSiteAposta) {
            const char* finalMessage = "Parabéns! Você se\ntornou o novo Sílvio Santos!";
            
            int fontSize = 20; 
            
            int textWidth = MeasureText("tornou o novo Sílvio Santos!", fontSize); 
            
            int textX = gameAreaLimitX + (upgradeColumnWidth / 2) - (textWidth / 2);
            
            int textY = 50 + 70*5 + 35; 
            
            DrawText(finalMessage, textX, textY, fontSize, TEXT_ON_YELLOW); 
        }

        std::string dinheiroText = "Dinheiro: R$" + std::to_string(dinheiro);
        DrawText(dinheiroText.c_str(), 10, 10, 30, TEXT_ON_GREEN); 
        
        int dpsInteiro = (int)std::round(dinheiroPorSegundo); 
        std::string dpsText = "Rendimento: R$" + std::to_string(dpsInteiro) + "/s";
        DrawText(dpsText.c_str(), 10, 50, 20, TEXT_ON_GREEN);
        
        DrawText("LOJA DE UPGRADES", gameAreaLimitX + 10, 10, 20, TEXT_ON_YELLOW); 
        
        EndDrawing();
    }

    SaveGame();

    UnloadMusicStream(backgroundMusic);
    CloseAudioDevice();
    UnloadTexture(moeda);
    CloseWindow();

    return 0;
}