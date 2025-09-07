package br.edu.ifspcjo.ads.web3.exercicio2.repository;

import br.edu.ifspcjo.ads.web3.exercicio2.domain.model.User;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface UserRepository extends JpaRepository<User, Long> {
}
