const nums = [ 1, 2, 3, 4, 5, 6 ];

const doubled = nums.map((element) => element * 2);

const evens = nums.filter((element) => !(element % 2));
const odds = nums.filter((element) => element % 2);
const total = nums.reduce((accumulator, current) => accumulator + current, 30);

// Our custom map function
const map = (elements, cb) => {
	const newArr = [];

	for (let i = 0; i < elements.length; i++) {
		newArr[i] = cb(elements[i]);
	}
	return newArr;
};

// our custom filter
const filter = (elements, cb) => {
	const newArr = [];

	for (let i = 0; i < elements.length; i++) {
		// we only picking elements that pass our callback
		if (cb(elements[i])) {
			//newArr[i] = elements[i];
			newArr.push(elements[i]);
		}
	}
	return newArr;
};

// our custom reduce
const reduce = (elements, cb, startingValue) => {
	let memo = startingValue;

	// check if someone has provided a starting value
	if (memo === undefined) {
		memo = elements.shift();
	}

	for (let i = 0; i < elements.length; i++) {
		memo = cb(memo, elements[i]);
	}
	return memo;
};

const anotherDoubled = map(nums, (element) => element * 2);
const greaterThan3 = filter(nums, (element) => element > 3);
const anotherTotal = reduce(nums, (accumulator, current) => accumulator + current, 10);
console.log(anotherTotal);
