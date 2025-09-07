package br.edu.ifspcjo.ads.web3.exercicio2.domain.controller;

import br.edu.ifspcjo.ads.web3.exercicio2.dto.UserDTO;
import br.edu.ifspcjo.ads.web3.exercicio2.domain.model.User;
import br.edu.ifspcjo.ads.web3.exercicio2.service.UserService;
import jakarta.validation.Valid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/users")
public class UserController {
    @Autowired
    private UserService userService;

    @PostMapping
    public ResponseEntity<User> createUser(@Valid @RequestBody UserDTO userDTO) {
        User user = userService.createUser(userDTO);
        return ResponseEntity.status(HttpStatus.CREATED).body(user);
    }
}
