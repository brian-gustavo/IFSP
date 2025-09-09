package br.edu.ifspcjo.ads.web3.exercicio3.service;

import br.edu.ifspcjo.ads.web3.exercicio3.domain.model.Usuario;
import br.edu.ifspcjo.ads.web3.exercicio3.repository.UsuarioRepository;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Optional;

@Service
public class UsuarioService {
    @Autowired
    private UsuarioRepository usuarioRepository;

    public Usuario atualizar(Long codigo, Usuario usuario) {
        Optional<Usuario> usuarioSalvo = usuarioRepository.findById(codigo);
        
        if (usuarioSalvo.isEmpty()) {
            throw new IllegalArgumentException("Usuário não encontrado!");
        }
        
        BeanUtils.copyProperties(usuario, usuarioSalvo.get(), "codigo");
        return usuarioRepository.save(usuarioSalvo.get());
    }

    public void atualizarAtivo(Long codigo, Boolean ativo) {
        Optional<Usuario> usuarioSalvo = usuarioRepository.findById(codigo);
        
        if (usuarioSalvo.isEmpty()) {
            throw new IllegalArgumentException("Usuário não encontrado!");
        }
        
        usuarioSalvo.get().setAtivo(ativo);
        usuarioRepository.save(usuarioSalvo.get());
    }
}
