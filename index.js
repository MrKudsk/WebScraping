const puppeteer = require('puppeteer');

async function main() {
   const browser = await puppeteer.launch({
	executablePath: '/usr/bin/chromium-browser',});
   const page = await browser.newPage();
   await page.goto("https://learnwebcode.github.io/practice-requests/");
   await page.screenshot({path: "amazing.png",
	fullPage: true,});
   await browser.close();
}

main();
