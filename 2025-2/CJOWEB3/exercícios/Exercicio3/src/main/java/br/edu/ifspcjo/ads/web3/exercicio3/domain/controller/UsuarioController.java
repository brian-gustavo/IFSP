package br.edu.ifspcjo.ads.web3.exercicio3.domain.controller;

import br.edu.ifspcjo.ads.web3.exercicio3.domain.model.Usuario;
import br.edu.ifspcjo.ads.web3.exercicio3.repository.UsuarioRepository;
import br.edu.ifspcjo.ads.web3.exercicio3.service.UsuarioService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import jakarta.validation.Valid;

@RestController
@RequestMapping("/usuarios")
public class UsuarioController {
    @Autowired
    private UsuarioService usuarioService;
    
    @Autowired
    private UsuarioRepository usuarioRepository;
    
    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    public Usuario criar(@RequestBody Usuario usuario) {
        return usuarioRepository.save(usuario);
    }
    
    @PutMapping("/{codigo}")
    public ResponseEntity<Usuario> atualizar(@PathVariable Long codigo, @Valid @RequestBody Usuario usuario) {
        Usuario usuarioSalvo = usuarioService.atualizar(codigo, usuario);
        return ResponseEntity.ok(usuarioSalvo);
    }

    @PutMapping("/{codigo}/ativo")
    @ResponseStatus(HttpStatus.NO_CONTENT)
    public void atualizarAtivo(@PathVariable Long codigo, @RequestBody Boolean ativo) {
        usuarioService.atualizarAtivo(codigo, ativo);
    }
}
