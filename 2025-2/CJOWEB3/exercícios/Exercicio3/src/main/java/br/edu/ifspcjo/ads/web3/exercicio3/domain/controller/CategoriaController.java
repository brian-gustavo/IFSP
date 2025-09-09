package br.edu.ifspcjo.ads.web3.exercicio3.domain.controller;

import br.edu.ifspcjo.ads.web3.exercicio3.domain.model.Categoria;
import br.edu.ifspcjo.ads.web3.exercicio3.repository.CategoriaRepository;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import jakarta.validation.Valid;

@RestController
@RequestMapping("/categorias")
public class CategoriaController {
    @Autowired
    private CategoriaRepository categoriaRepository;
    
    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    public Categoria criar(@Valid @RequestBody Categoria categoria) {
        return categoriaRepository.save(categoria);
    }
    
    @PutMapping("/{codigo}")
    public ResponseEntity<Categoria> atualizar(@PathVariable Long codigo, @Valid @RequestBody Categoria categoria) {
        Categoria categoriaSalva = categoriaRepository.findById(codigo)
                .orElseThrow(() -> new IllegalArgumentException("Categoria não encontrada!"));

        BeanUtils.copyProperties(categoria, categoriaSalva, "codigo");
        return ResponseEntity.ok(categoriaRepository.save(categoriaSalva));
    }

    @DeleteMapping("/{codigo}")
    @ResponseStatus(HttpStatus.NO_CONTENT)
    public void remover(@PathVariable Long codigo) {
        categoriaRepository.deleteById(codigo);
    }
}
