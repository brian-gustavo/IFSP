package br.edu.ifspcjo.ads.web3.exercicio3.repository;

import br.edu.ifspcjo.ads.web3.exercicio3.domain.model.Usuario;
import org.springframework.data.jpa.repository.JpaRepository;

public interface UsuarioRepository extends JpaRepository<Usuario, Long> {
}
