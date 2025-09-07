package br.edu.ifspcjo.ads.web3.exercicio2.dto;

import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.Size;

public class CategoryDTO {
    @NotBlank(message = "O nome da categoria é obrigatório.")
    @Size(max = 50, message = "O nome da categoria não pode ter mais de 50 caracteres.")
    private String name;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
