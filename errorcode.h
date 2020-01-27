
class ERROR_CODE {
public:
	enum Error_code { duplicate_error, not_present, success };

	class INPUT_INVALID {
		public:
			INPUT_INVALID() {
				std::cerr << "INVALID_INPUT:" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
		};

	class INPUT_NOT_A_VALID_SELECTION {
    public:
        INPUT_NOT_A_VALID_SELECTION() { std::cerr << "INPUT_NOT_A_VALID_SELECTION: " << std::endl; } 
    };

};

