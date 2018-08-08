#pragma once

class Score {
	private:
		int wins;
		int loses;
		int draws;

	public:
		Score();
		~Score();

		// Getters
		int getWins();
		int getLoses();
		int getDraws();

		// Setters
		void incWins();
		void incLoses();
		void incDraws();
};

