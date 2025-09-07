package br.edu.ifspcjo.ads.web3.exercicio2.service;

import br.edu.ifspcjo.ads.web3.exercicio2.dto.CategoryDTO;
import br.edu.ifspcjo.ads.web3.exercicio2.domain.model.Category;
import br.edu.ifspcjo.ads.web3.exercicio2.repository.CategoryRepository;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class CategoryService {
    @Autowired
    private CategoryRepository categoryRepository;

    public Category createCategory(CategoryDTO categoryDTO) {
        Category category = new Category();
        BeanUtils.copyProperties(categoryDTO, category);
        return categoryRepository.save(category);
    }
}
