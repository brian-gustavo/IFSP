package br.edu.ifspcjo.ads.web3.exercicio1.repository;

import br.edu.ifspcjo.ads.web3.exercicio1.domain.model.Categoria;
import org.springframework.data.jpa.repository.JpaRepository;

public interface CategoriaRepository extends JpaRepository<Categoria, Long> {
}
