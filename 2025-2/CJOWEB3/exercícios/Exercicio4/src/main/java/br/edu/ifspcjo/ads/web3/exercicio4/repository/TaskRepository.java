package br.edu.ifspcjo.ads.web3.exercicio4.repository;

import br.edu.ifspcjo.ads.web3.exercicio4.domain.model.Task;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface TaskRepository extends JpaRepository<Task, Long> {
}
