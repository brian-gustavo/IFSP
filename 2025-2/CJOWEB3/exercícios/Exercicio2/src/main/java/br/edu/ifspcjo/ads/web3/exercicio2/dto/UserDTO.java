package br.edu.ifspcjo.ads.web3.exercicio2.dto;

import jakarta.validation.constraints.Email;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.Size;

public class UserDTO {
    @NotBlank(message = "O nome é obrigatório.")
    @Size(max = 100, message = "O nome não pode ter mais de 100 caracteres.")
    private String name;

    @NotBlank(message = "O e-mail é obrigatório.")
    @Email(message = "O e-mail deve ter um formato válido.")
    @Size(max = 150, message = "O e-mail não pode ter mais de 150 caracteres.")
    private String email;

    @NotBlank(message = "A senha é obrigatória.")
    private String password;

    private String phone;
    
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }
}
