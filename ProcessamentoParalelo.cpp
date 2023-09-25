// ProcessamentoParalelo.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>
#include <mutex>
#include <functional>
#include <deque>
#include "ListaDuplaEncad.h"
#include "ListaSimplesEncad.h"
#include "Processamento.h"

class Gerador {

public:

	static std::vector<int> geraNumeros(int n) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<>intDistribution(0, 10000);
		std::vector<int> vetorRandom;

		for (int i = 0; i < n; i++) {
			vetorRandom.push_back(intDistribution(gen));
		}

		return vetorRandom;
	}
};

class ThreadPool {
public:
	ThreadPool(size_t numThreads) {
		for (size_t i = 0; i < numThreads; ++i) {
			threads.emplace_back([this] { workerThread(); });
		}
	}

	~ThreadPool() {
		stop = true;
		for (std::thread& thread : threads) {
			thread.join();
		}
	}

	void enqueueTask(std::function<void()> task) {
		{
			std::unique_lock<std::mutex> lock(queueMutex);
			tasks.push_back(task);
		}
		condition.notify_one();
	}

private:
	void workerThread() {
		while (true) {
			std::function<void()> task;
			{
				std::unique_lock<std::mutex> lock(queueMutex);
				condition.wait(lock, [this] { return stop || !tasks.empty(); });
				if (stop && tasks.empty()) {
					return;
				}
				task = tasks.front();
				tasks.pop_front();
			}
			task(); // Executa a tarefa
		}
	}

	std::vector<std::thread> threads;
	std::deque<std::function<void()>> tasks;
	std::mutex queueMutex;
	std::condition_variable condition;
	bool stop = false;
};

int main()
{
	//LISTAS COM 1000
	ListaSimplesEncad listaSimples1;
	ListaDuplaEncad listaDupla1;
	std::vector<int> vetor1;

	listaSimples1.addVector(Gerador::geraNumeros(10));
	listaDupla1.addVector(Gerador::geraNumeros(10));
	vetor1 = Gerador::geraNumeros(10);

	//LISTAS COM 3000
	ListaSimplesEncad listaSimples2;
	ListaDuplaEncad listaDupla2;
	std::vector<int> vetor2;

	listaSimples2.addVector(Gerador::geraNumeros(30));
	listaDupla2.addVector(Gerador::geraNumeros(30));
	vetor2 = Gerador::geraNumeros(30);

	//LISTAS COM 5000
	ListaSimplesEncad listaSimples3;
	ListaDuplaEncad listaDupla3;
	std::vector<int> vetor3;

	listaSimples3.addVector(Gerador::geraNumeros(50));
	listaDupla3.addVector(Gerador::geraNumeros(50));
	vetor3 = Gerador::geraNumeros(50);

	//LISTAS COM 10000
	ListaSimplesEncad listaSimples4;
	ListaDuplaEncad listaDupla4;
	std::vector<int> vetor4;

	listaSimples1.addVector(Gerador::geraNumeros(10));
	listaDupla1.addVector(Gerador::geraNumeros(10));
	vetor1 = Gerador::geraNumeros(10);

	Processamento process;

	/*process.processaSemParalelo(vetor1, vetor2, vetor3, vetor4);
	process.processaSemParalelo(listaSimples1, listaSimples2, listaSimples3, listaSimples4);
	process.processaSemParalelo(listaDupla1, listaDupla2, listaDupla3, listaDupla4);*/

	ThreadPool pool(2);

	pool.enqueueTask([&process, vetor1, vetor2, vetor3, vetor4] {
		process.processaVetor(vetor1, vetor2, vetor3, vetor4);
	});
	pool.enqueueTask([&process, listaSimples1, listaSimples2, listaSimples3, listaSimples4] {
		process.processaListaSimples(listaSimples1, listaSimples2, listaSimples3, listaSimples4);
	});
	pool.enqueueTask([&process, listaDupla1, listaDupla2, listaDupla3, listaDupla4] {
		process.processaListaDupla(listaDupla1, listaDupla2, listaDupla3, listaDupla4);
	});


	//std::thread thread_obj(&Processamento::processaSemParaleloVetor, &process, vetor1, vetor2, vetor3, vetor4);
	/*std::thread thread_obj2(&Processamento::processaSemParaleloListaSimples, &process, listaSimples1, listaSimples2, listaSimples3, listaSimples4);
	std::thread thread_obj3(&Processamento::processaSemParaleloListaDupla, &process, listaDupla1, listaDupla2, listaDupla3, listaDupla4);*/

	return 0;
}
