package br.edu.ifspcjo.ads.web3.exercicio2.service;

import br.edu.ifspcjo.ads.web3.exercicio2.dto.UserDTO;
import br.edu.ifspcjo.ads.web3.exercicio2.domain.model.User;
import br.edu.ifspcjo.ads.web3.exercicio2.repository.UserRepository;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UserService {
    @Autowired
    private UserRepository userRepository;

    public User createUser(UserDTO userDTO) {
        User user = new User();
        BeanUtils.copyProperties(userDTO, user);
        return userRepository.save(user);
    }
}
